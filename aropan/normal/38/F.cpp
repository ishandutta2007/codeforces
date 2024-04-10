#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int MAXN = 30 * 30 * 30;

int n, k;
map <string, int> ID;
int f[MAXN];
int first[MAXN], second[MAXN], winner[MAXN];
int cnt[MAXN], point[MAXN];

int dfs(string s)
{
    if (ID.find(s) == ID.end()) return 0;
    int k = ID[s];
    if (winner[k]) return 0;
    
    point[k] = 0;
    for (int i = 0; i < (int)s.size(); i++)
        point[k] += s[i] - 'a' + 1;
    
    point[k] *= *max_element(s.begin(), s.end()) - 'a' + 1;
    point[k] += cnt[k];
    
    
    winner[k] = 2;
    first[k] = 0;
    second[k] = 0;
    
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 2; j++)
        {
            string c;
            if (j)
                c = s + (char)(i + 'a');
            else
                c = (char)(i + 'a') + s;
                
            if (ID.find(c) != ID.end())
            {
                dfs(c);
                int x = ID[c];
                
                if (winner[k] == 1 && winner[x] == 1) continue;
                
                if (winner[k] == 2 && winner[x] == 2)
                {
                    winner[k] = 1;
                    first[k] = second[x] + point[x];
                    second[k] = first[x];
                }
                
                
                if (
                    first[k] < second[x] + point[x] || 
                    first[k] == second[x] + point[x] && second[k] > first[x]
                )
                {
                    first[k] = second[x] + point[x];
                    second[k] = first[x];
                }
            }
        }
    return 0;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int x = 0; x < (int)s.size(); x++)
            for (int y = x; y < (int)s.size(); y++)
            {
                string c = s.substr(x, y - x + 1);
                if (ID.find(c) == ID.end()) ID[c] = ++k;
                int id = ID[c];
                cnt[id] += f[id] <= i;
                f[id] = i + 1;
            }
    }
    ID[""] = ++k;
    
    dfs("");
    
    printf("%s\n%d %d\n", winner[k] == 1? "First" : "Second", first[k], second[k]);
    return 0;
}
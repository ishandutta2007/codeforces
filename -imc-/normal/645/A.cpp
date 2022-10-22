#include <bits/stdc++.h>

using namespace std;

vector<char> read()
{
    vector<char> v;
    
    for (int i = 0; i < 4; i++)
    {
        char c;
        scanf(" %c", &c);
        v.push_back(c);
    }
    
    swap(v[2], v[3]);
    
    v.erase(find(v.begin(), v.end(), 'X'));
    
    int p = find(v.begin(), v.end(), 'A') - v.begin();
    vector<char> res(3);
    for (int i = 0; i < 3; i++)
        res[i] = v[(p + i) % 3];
    return res;
}

int main()
{
    vector<char> a = read(), b = read();
    printf("%s\n", a == b ? "YES" : "NO");
    
    return 0;
}
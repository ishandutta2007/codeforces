#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const int p =  1e9 + 7;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}



vector<int> Z(string s)
{
int n = s.length();
vector<int> z(n);
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}

bool check(string s, string p)
{
    int S = s.length();
    int P = p.length();
    
    int idx = 0;
    for (int i = 0; i<S&&idx<P; i++) if (s[i]==p[idx]) idx++;
    return (idx==P);
}

void op(vector<vector<char>> &a, pair<int, int> p)
{
    int x = p.first;
    int y = p.second;
    if (a[x][y]=='L')
    {
        a[x][y] = 'U'; 
        a[x+1][y] = 'D';
        a[x][y+1] = 'U';
        a[x+1][y+1] = 'D';
    }
    else
    {
        a[x][y] = 'L';
        a[x][y+1] = 'R';
        a[x+1][y] = 'L';
        a[x+1][y+1] = 'R';
    }
}

vector<pair<int, int>> solve(vector<vector<char>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<pair<int, int>> answer;
    for (int i = 0; i+1<n; i+=2)
    {
        for (int j = 0; j<m; j++)
        {
            if (a[i][j]=='U') continue;
            int k = 0;
            while (a[i+k][j+k]=='L') k++;
            if (a[i+k][j+k]== 'U') 
            for (int c = k-1; c>=0; c--) 
            {
                op(a, mp(i+c+1, j+c));  
                answer.push_back(mp(i+c+1, j+c)); 
                op(a, mp(i+c, j+c)); 
                answer.push_back(mp(i+c, j+c));
            }
            else 
            {
                op(a, mp(i+k-1, j+k-1)); 
                answer.push_back(mp(i+k-1, j+k-1));             
                for (int c = k-2; c>=0; c--) 
                {
                    op(a, mp(i+c+1, j+c));  
                    answer.push_back(mp(i+c+1, j+c)); 
                    op(a, mp(i+c, j+c)); 
                    answer.push_back(mp(i+c, j+c));
                }                
            }
        }
    }
    return answer;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<string> a1(n);
    vector<string> a2(n);
    for (int i = 0; i<n; i++) cin>>a1[i];
    for (int i = 0; i<n; i++) cin>>a2[i];
    
    vector<vector<char>> A1;
    vector<vector<char>> A2;


    A1 = vector<vector<char>> (n, vector<char>(m));
    A2 = vector<vector<char>> (n, vector<char>(m));
    for (int i = 0; i<n; i++) 
    for (int j = 0; j<m; j++) A1[i][j] = a1[i][j];
    for (int i = 0; i<n; i++) 
    for (int j = 0; j<m; j++) A2[i][j] = a2[i][j]; 
    
    /*for (int i = 0; i<n; i++) print(A1[i]);
    
    op(A1, mp(0, 1));
    
    for (int i = 0; i<n; i++) print(A1[i]); */   
    auto it1 = solve(A1);
    auto it2 = solve(A2);
    cout<<it1.size()+it2.size()<<endl;
    for (auto it: it1) cout<<it.first+1<<' '<<it.second+1<<endl;
    for (int i = it2.size() - 1; i>=0; i--) cout<<it2[i].first+1<<' '<<it2[i].second+1<<endl;
    
}
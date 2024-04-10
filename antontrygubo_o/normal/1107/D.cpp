#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int vecgcd(vector<int> a)
{
    int res = a[0];
    for (int i = 0; i<a.size(); i++) res = __gcd(res, a[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin>>n;
    m = n;
    char lol;
    bitset<4> kek;
    vector<vector<bool>> a(n, vector<bool>(m));
    for (int i = 0; i<n; i++)
    for (int j = 0; j<n/4; j++) 
    {
        cin>>lol;
        if ('0'<=lol&&lol<='9') kek = bitset<4>(lol);
        else kek = bitset<4>((int)(lol - 'A') + 10);
        for (int k = 0; k<4; k++) a[i][4*j+k] = kek[3-k];
    }
    
    vector<int> gcd1(n);
    for (int i = 0; i<n; i++)
    {
        vector<int> kek;
        int counter = 1;
        for (int j = 1; j<m; j++)
        {
            if (a[i][j]==a[i][j-1]) counter++;
            else {kek.push_back(counter); counter = 1;}
        }
        kek.push_back(counter);
        gcd1[i] = vecgcd(kek);
    }
    
    vector<int> gcd2(m);
    for (int i = 0; i<m; i++)
    {
        vector<int> kek;
        int counter = 1;
        for (int j = 1; j<n; j++)
        {
            if (a[j][i]==a[j-1][i]) counter++;
            else {kek.push_back(counter); counter = 1;}
        }
        kek.push_back(counter);
        gcd2[i] = vecgcd(kek);
    }
    
    //for (int i = 0; i<n; i++) print(a[i]);
    
    int g1 = vecgcd(gcd1);
    int g2 = vecgcd(gcd2);
    cout<<__gcd(g1, g2)<<endl;
    


}
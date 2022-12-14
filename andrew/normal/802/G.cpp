#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s,s1;
ll c,i,j,m;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s1;
    s="heidi";
    c=0;
    m=s1.size();
    i=0;
    while(c<5 and i<m)
    {
        if(s[c]==s1[i])c++;
        i++;
    }
    if(c==5)cout << "YES"; else cout << "NO";
    cout << endl;
    return 0;
}
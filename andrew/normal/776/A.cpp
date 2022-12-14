#include <iostream>
#include <cstdio>
#include <cmath>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define endl "\n"
using namespace std;

string s[401],s1,s2,s3,s4;
ll sc,m,n,i,j,l,r,x,a[100001],d,c,ans;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1 >> s2;
    cin  >> n;
    cout << s1 << " " << s2 << endl;
    for(i=0;i<n;i++)
    {
      cin >> s3 >> s4;
      if(s1==s3)s1=s4; else s2=s4;
      cout << s1 << " " << s2 << endl;
    }
    return 0;
}
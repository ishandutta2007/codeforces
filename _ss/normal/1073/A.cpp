#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
    //freopen("diverse.inp","r",stdin);
    //freopen("diverse.out","w",stdout);
    int n,a[29],t;
    string s;
    bool kt;
    cin>>n>>s;
    for (int i=0;i<=n-2;i++)
    {
        for (int j=1;j<=28;j++) a[j]=0;
        a[s[i]-'a'+1]++;
        for (int j=i+1;j<=n-1;j++)
        {
            t=s[j]-'a'+1;
            a[t]++;
            kt=true;
            for (int h=1;h<=28;h++)
            {
                if (a[h]>(j-i+1)/2)
                {
                    kt=false;
                    break;
                }
            }
            if (kt)
            {
                cout<<"YES"<<endl;
                for (int h=i;h<=j;h++) cout<<s[h];
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
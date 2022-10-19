#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[2005],t[2005];
char temp[2005];
int n;
int ans[6050],nn;
void solve(int x)
{
    ans[nn++]=x;
    for(int i=n-x,j=n-1;i<j;i++,j--)
    {
        swap(s[i],s[j]);
    }
    int num=0;
    for(int i=n-x;i<n;i++)
        temp[num++]=s[i];
    for(int i=0;i<n-x;i++)
        temp[num++]=s[i];
    for(int i=0;i<n;i++)
        s[i]=temp[i];
}
int main()
{
    cin>>n;
    scanf("%s",s);
    scanf("%s",t);
    string ss1,ss2;
    ss1=s;
    ss2=t;
    sort(ss1.begin(),ss1.end());
    sort(ss2.begin(),ss2.end());
    if(ss1!=ss2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j]==t[i])
            {
                solve(n-j-1);
                //cout<<"<<<<"<<n-j-1<<" "<<s<<endl;
                solve(1);
                //cout<<"<<<<"<<1<<" "<<s<<endl;
                solve(n);
                //cout<<"<<<<"<<n<<" "<<s<<endl;
                break;
            }
        }
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
    return 0;
}
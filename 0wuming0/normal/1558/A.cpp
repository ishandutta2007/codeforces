#include"bits/stdc++.h"
using namespace std;
void solve(int n,int m,int a,int b,set<int>&st)
{
    int l=abs(n-b);
    int r=min(n,a)+min(m,b);//cout<<"<<"<<n<<" "<<m<<" "<<a<<" "<<b<<"   "<<l<<" "<<r<<endl;
    for(int i=l;i<=r;i+=2)
    {
        st.insert(i);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        set<int>st;
        int n=(a+b)/2;
        int m=a+b-n;
        solve(n,m,a,b,st);
        solve(n,m,b,a,st);
        bool flag=0;
        printf("%d\n",(int)st.size());
        for(auto a:st)
        {
            if(flag)putchar(' ');
            else flag=1;
            printf("%d",a);
        }
        printf("\n");
    }
    return 0;
}
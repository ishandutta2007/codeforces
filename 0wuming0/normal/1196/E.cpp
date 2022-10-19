#include"bits/stdc++.h"
using namespace std;
void solve(int a,int b,int x,int y)
{
    if(b*3+1<a)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        set<pair<int,int> >st;
        st.insert(make_pair(x,y));
        for(int i=0;i<b;i++)
        {
            printf("%d %d\n",x,y+2*i+1);
            printf("%d %d\n",x,y+2*i+2);
            st.insert(make_pair(x+1,y+2*i+1));
            st.insert(make_pair(x-1,y+2*i+1));
        }
        a-=b;
        while(a--)
        {
            printf("%d %d\n",st.begin()->first,st.begin()->second);
            st.erase(st.begin());
        }
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
        if(a>=b)
        {
            solve(a,b,1001,1000);
        }
        else
        {
            solve(b,a,1000,1000);
        }
    }
    return 0;
}
    #include<cstdio>  
    #include<cstring>  
    #include<stack>  
    #include<iostream>  
    #include<algorithm>  
    using namespace std;  
    #define N 5005  
      
    int dp[N],s[N];  
    struct node  
    {  
        int x,y,id;  
    }e[N];  
    bool cmp(node a,node b)  
    {  
        return a.x<b.x;  
    }  
    int main()  
    {  
        int n,w,h,i,j;  
        while(scanf("%d%d%d",&n,&w,&h)!=EOF)  
        {  
            for(i=1;i<=n;i++)  
            {  
                scanf("%d%d",&e[i].x,&e[i].y);  
                e[i].id=i;  
            }  
            sort(e+1,e+n+1,cmp);  
            memset(dp,0,sizeof(dp));  
            memset(s,0,sizeof(s));  
            int t;  
            int loc;  
            for(i=1;i<=n;i++)  
            {  
                t=0;  
                loc=i;  
                if(e[i].x<=w||e[i].y<=h)continue;  
                for(j=1;j<=i;j++)  
                {  
                    if(e[j].x<=w||e[j].y<=h)continue;  
                    if(e[j].x!=e[i].x&&e[i].y>e[j].y)  
                    {  
                        if(dp[j]>t)  
                        {  
                            t=dp[j];  
                            loc=j;  
                        }  
                    }  
                }  
                dp[i]=t+1;  
                s[e[i].id]=e[loc].id;  
            }  
            int ans=-1;  
            for(i=1;i<=n;i++)  
            {  
                if(ans<dp[i])  
                {  
                    ans=dp[i];  
                    loc=e[i].id;  
                }  
            }  
            stack<int>ss;  
            printf("%d\n",ans);  
            if(ans!=0)  
            {  
                while(1)  
                {  
                    ss.push(loc);  
                    if(s[loc]==loc)break;  
                    loc=s[loc];  
                }  
                while(ss.size())  
                {  
                    printf("%d ",ss.top());  
                    ss.pop();  
                }  
                printf("\n");  
            }  
        }  
        return 0;  
    }
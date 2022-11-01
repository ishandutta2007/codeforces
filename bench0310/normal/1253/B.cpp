#include <bits/stdc++.h>

using namespace std;

int main()
{
    auto out=[]()
    {
        printf("-1\n");
        exit(0);
    };
    int n;
    scanf("%d",&n);
    set<int> now;
    set<int> today;
    int cnt=0;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a<0)
        {
            if(now.find(-a)==now.end()) out();
            now.erase(-a);
        }
        else
        {
            if(now.find(a)!=now.end()) out();
            if((now.empty()&&cnt>0)||today.find(a)!=today.end())
            {
                if(!now.empty()) out();
                res.push_back(cnt);
                cnt=0;
                today.clear();
                now.insert(a);
                today.insert(a);
            }
            else
            {
                now.insert(a);
                today.insert(a);
            }
        }
        cnt++;
    }
    if(!now.empty()) out();
    res.push_back(cnt);
    printf("%d\n",(int)res.size());
    for(int t:res) printf("%d ",t);
    printf("\n");
    return 0;
}
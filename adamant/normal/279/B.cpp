#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int n,t;
    cin>>n>>t;
    int*a=new int[n];
    int se=0;
    int cure=0;
    bool fd=1;
    int ans=0;
    int cur_sum=0;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    cure+=a[i];
    if(cure>t && fd)
    ans=se=i,cur_sum=cure-a[i],fd=0;
    }
    if(fd)
    {
    cout<<n<<endl;
    return 0;
    }
    int maxa=ans;
    cur_sum-=a[0],ans--;
    for(int fi=1;fi<n;fi++)
    {
            //cout<<ans<<endl;
            for(int sec=se;sec<n;sec++)
            {
            cur_sum+=a[sec];
            //cout<<cur_sum<<" ok"<<endl;
            if(cur_sum<=t)
            ans++;
            else
            {
            cur_sum-=a[sec];
            se=sec;
            break;
            }
            }
            //cout<<ans<<endl;
            if(ans>maxa)
            maxa=ans;
            cur_sum-=a[fi],ans--;
    }
    cout<<maxa<<endl;
    //system("pause");
}
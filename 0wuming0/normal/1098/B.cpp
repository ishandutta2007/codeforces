#include"bits/stdc++.h"
using namespace std;
map<string,int>mp;
map<string,string>mp2;
map<string,int>mpl[300005];
map<string,int>mpr[300005];
//string s[300005];
char *s[300005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)s[i]=(char *)malloc(sizeof(char)*(m+2));
    for(int i=0;i<n;i++)scanf("%s",s[i]);//for(int i=0;i<n;i++)cout<<s[i]<<endl;
        mp["AG"]=0;
        mp["AC"]=0;
        mp["AT"]=0;
        mp["CG"]=0;
        mp["CA"]=0;
        mp["CT"]=0;
        mp["GA"]=0;
        mp["GC"]=0;
        mp["GT"]=0;
        mp["TA"]=0;
        mp["TC"]=0;
        mp["TG"]=0;
        mp2["AG"]="CT";//cout<<"ok"<<endl;
        mp2["AC"]="GT";
        mp2["AT"]="CG";
        mp2["CG"]="AT";
        mp2["CT"]="AG";//cout<<"ok"<<endl;
        mp2["GT"]="AC";
    for(int i=0;i<n;i++)for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        string s0=it->first;
        int sum=0;
        for(int j=0;j<m;j++)if(s0[j%2]==s[i][j])
        {
            sum++;
        }
        mpr[i][s0]=sum;
    }//return 0;
    for(int j=0;j<m;j++)for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        string s0=it->first;
        int sum=0;
        for(int i=0;i<n;i++)if(s0[i%2]==s[i][j])
        {
            sum++;
        }//cout<<j<<endl;
        mpl[j][s0]=sum;
    }
    int flag,ans=-1;
    map<string,string>::iterator save;
    for(map<string,string>::iterator it=mp2.begin();it!=mp2.end();it++)
    {
        int now=0;
        string s0[2];
        string s1[2];
        s0[0]=it->first;
        s0[1]=it->second;
        s1[0]=s0[0];
        s1[1]=s0[1];
        swap(s1[0][0],s1[0][1]);
        swap(s1[1][0],s1[1][1]);
        for(int i=0;i<n;i++)
        {
            now+=max(mpr[i][s0[i%2]],mpr[i][s1[i%2]]);
        }
        if(now>ans)
        {
            flag=0;
            ans=now;
            save=it;
        }
    }//ans=-1;
    for(map<string,string>::iterator it=mp2.begin();it!=mp2.end();it++)
    {
        int now=0;
        string s0[2];
        string s1[2];
        s0[0]=it->first;//cout<<"<<<"<<s0[0]<<endl;
        s0[1]=it->second;
        s1[0]=s0[0];
        s1[1]=s0[1];
        swap(s1[0][0],s1[0][1]);
        swap(s1[1][0],s1[1][1]);
        for(int i=0;i<m;i++)
        {
            now+=max(mpl[i][s0[i%2]],mpl[i][s1[i%2]]);
        }
        if(now>ans)
        {//cout<<"<<<"<<now<<" "<<s0[0]<<endl;
            flag=1;
            ans=now;
            save=it;
        }
    }
    if(flag==0)
    {
        string s0[2];
        string s1[2];
        s0[0]=save->first;
        s0[1]=save->second;
        s1[0]=s0[0];
        s1[1]=s0[1];
        swap(s1[0][0],s1[0][1]);
        swap(s1[1][0],s1[1][1]);
        for(int i=0;i<n;i++)
        {
            if(mpr[i][s0[i%2]]>mpr[i][s1[i%2]])
            {
                for(int j=0;j<m;j++)
                {
                    s[i][j]=s1[i%2][j%2==0];
                }
            }
            else
            {
                for(int j=0;j<m;j++)
                {
                    s[i][j]=s0[i%2][j%2==0];
                }
            }
        }
    }
    else
    {//cout<<"ok"<<endl;
        string s0[2];
        string s1[2];
        s0[0]=save->first;
        s0[1]=save->second;
        s1[0]=s0[0];
        s1[1]=s0[1];
        swap(s1[0][0],s1[0][1]);
        swap(s1[1][0],s1[1][1]);
        for(int j=0;j<m;j++)
        {//cout<<">>>"<<s0[j%2]<<" "<<s1[j%2]<<endl;
            if(mpl[j][s0[j%2]]>mpl[j][s1[j%2]])
            {
                for(int i=0;i<n;i++)
                {
                    s[i][j]=s1[j%2][i%2==0];
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    s[i][j]=s0[j%2][i%2==0];
                }
            }
        }
    }//cout<<ans<<endl;//cout<<mpl[0]["AC"]<<endl;
    for(int i=0;i<n;i++)printf("%s\n",s[i]);
    for(int i=0;i<n;i++)free(s[i]);
    return 0;
}
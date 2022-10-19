#include"bits/stdc++.h"
using namespace std;
const double PI=acos(-1.0);
struct com
{
    double x,y;
    com(double _x=0.0,double _y=0.0)
    {
        x=_x;
        y=_y;
    }
    com operator-(const com&b)const
    {
        return com(x-b.x,y-b.y);
    }
    com operator+(const com&b)const
    {
        return com(x+b.x,y+b.y);
    }
    com operator*(const com&b)const
    {
        return com(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
void change(com y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void fft(com y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        com wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h)
        {
            com w(1,0);
            for(int k=j;k<j+h/2;k++)
            {
                com u=y[k];
                com t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)for(int i=0;i<len;i++)
    {
        y[i].x/=len;
    }
}
#define maxn (1<<21)
com x1[maxn],x2[maxn];
int get(int s1[],int len1,int s2[],int len2,int s[])
{
    int len=1;
    while(len<len1*2||len<len2*2)len<<=1;
    for(int i=0;i<len1;i++)x1[i]=com(s1[len1-1-i],0);
    for(int i=len1;i<len;i++)x1[i]=com(0,0);
    for(int i=0;i<len2;i++)x2[i]=com(s2[len2-1-i],0);
    for(int i=len2;i<len;i++)x2[i]=com(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i=0;i<len;i++)x1[i]=x1[i]*x2[i];//cout<<len1<<" "<<len2<<"="<<len<<endl;
    fft(x1,len,-1);
    for(int i=0;i<len;i++)s[i]=(int)(x1[i].x+0.5);//cout<<"!!";for(int i=0;i<len;i++)cout<<s[i]<<endl;cout<<endl;
    for(int i=0;i<len;i++)
    {
        s[i+1]+=s[i]/10;
        s[i]%=10;
    }len--;
    //len=len1+len2-1;
    while(s[len]<=0&&len>0)len--;len++;
    for(int i=0,j=len-1;i<j;i++,j--)swap(s[i],s[j]);
    return len;
}
int check(int k)
{
    int now=1;
    for(int i=0;;i++)
    {
        if(now>=k)return i;
        now*=3;
    }
}
int len;
int s1[maxn+4],s2[maxn+4];int s[maxn+4];
int creat(int s[],int num)
{
    if(num==1)
    {
        s[0]=3;
        return 1;
    }
    int len1=creat(s,num/2);//cout<<"ok"<<num<<endl;for(int i=0;i<len1;i++)printf("%d",s[i]);putchar(10);
    int len=get(s,len1,s,len1,s);
    if(num%2)
    {
        for(int i=0;i<len;i++)s[i]*=3;
        for(int i=len-1;i>0;i--)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
        if(s[0]>9)
        {
            for(int i=len-1;i>=0;i--)
            {
                s[i+1]=s[i];
            }
            len++;
            s[0]=s[1]/10;
            s[1]%=10;
        }
    }
    return len;
}
int save;
int ok(char str[],int num,int n)
{//cout<<num<<endl;
    static int len;
    if(save==0)
    {
        len=creat(s,num);//for(int i=0;i<len;i++)printf("%d",s[i]);cout<<endl;
        save=num;
    }
    else
    {
        if(num!=save)
        {
            while(num!=save)
            {
                save--;
                int now=0;
                for(int i=0;i<len;i++)
                {
                    now+=s[i];
                    s[i]=now/3;
                    now%=3;
                    now*=10;
                }
                if(s[0]==0)
                {
                    len--;
                    for(int i=0;i<len;i++)s[i]=s[i+1];
                }
            }
        }
    }
    if(len>n)return 0;
    for(int i=0;i<n;i++)
    {
        if(str[i]-'0'<s[i])return 0;
        if(str[i]-'0'>s[i])return 1;
    }
    return 0;
}
int solve(char str[])
{
    int n=strlen(str);
    int aa=str[0]-'0';
    int num=(int)(log(aa)/log(3)+(n-1)*log(10)/log(3));
    num++;
    if(ok(str,num,n))num++;
    return num;
}
void chu2(char s[])
{
    int n=strlen(s);
    for(int i=0;i<n;i++)s[i]-='0';
    int now=0;
    for(int i=0;i<n;i++)
    {
        now+=s[i];
        s[i]=now/2;
        now%=2;
        now*=10;
    }
    if(now)s[n-1]++;
    for(int i=0;i<n;i++)s[i]+='0';
}
char str[1<<21];
int main()
{//creat(s,3000000);return 0;
    //creat(s,300000);creat(s,300000);creat(s,300000);return 0;
    scanf("%s",str);
    int len=strlen(str);
    if(len<3)
    {
        int t;
        sscanf(str,"%d",&t);
        if(t==1)
        {
            cout<<1<<endl;
            return 0;
        }
        int ans=1e9;
        ans=min(ans,check(t)*3);
        t=t/2+(t%2>0);
        ans=min(ans,check(t)*3+2);
        t=t/2+(t%2>0);
        ans=min(ans,check(t)*3+4);
        cout<<ans<<endl;
        return 0;
    }
    char *p=str;
    int ans=1e9;
    ans=min(ans,solve(p)*3);
    chu2(p);
    if(*p=='0')p++;
    ans=min(ans,solve(p)*3+2);
    chu2(p);
    if(*p=='0')p++;
    ans=min(ans,solve(p)*3+4);
    cout<<ans<<endl;
    return 0;
}
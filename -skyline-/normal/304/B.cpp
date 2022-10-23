#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool leapyear(int year)
{
    if((year%400==0)||(year%100!=0&&year%4==0))return true;
    else return false;
}
long long s;
int a,b,c,aa,bb,cc,v,i;
int main()
{
    int l,f=1,k;
    char ax[30],aax[30];
    cin>>ax;
    cin>>aax;
    l=strlen(ax);
    for(i=0;i<l;i++)
    {
         k=ax[i]-48;
         if(ax[i]==':')f++;
         else if(f==1)a=a*10+k;
         else if(f==2)b=b*10+k;
         else c=c*10+k;
    }
    f=1;
    l=strlen(aax);
    for(i=0;i<l;i++)
    {
         k=aax[i]-48;
         if(aax[i]==':')f++;
         else if(f==1)aa=aa*10+k;
         else if(f==2)bb=bb*10+k;
         else cc=cc*10+k;
    }
    if((a>aa)||(a==aa&&b>bb)||(a==aa&&b==bb&&c>cc))swap(a,aa),swap(b,bb),swap(c,cc);
    for(i=(a+1);i<aa;i++)
    {
         s+=leapyear(i);
         s+=365;
    }
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((bb>2)&&leapyear(aa)==1)s++;
    if((b<3)&&leapyear(a)==1)s++;
    for(i=12;i>b;i--)s+=month[i];
    s+=(month[i]-c);
    for(i=1;i<bb;i++)s+=month[i];
    s+=cc;
    if(a==aa)s-=365,s-=leapyear(a);
    cout<<s<<endl;
}
#include <bits/stdc++.h>
using namespace std;

//Testing for TLE, m83's code, trying to optimise :)

int main()
{
    ios::sync_with_stdio(false);
    int n,k,a,b;
    cin>>n>>k>>a>>b;string s;bool check=false;
    if(a>b)
    {
        while(a>b)
        {
            if(a>=k)
            {
                int h=a-b;
                for(int i=0;i<k && i<h;i++)
                {
                    s+="G";
                    a--;
                }
                if(a==b)
                break;
                else
                {
                s+="B";
                b--;}
                
            }
            else
            {
                for(int i=0;i<a;i++)
                s+="G";
                for(int i=0;i<b;i++)
                s=s+"B";
                check=true;
                break;
            }
            if(b<0)
            {
                s="NO";check=true;break;
            }
        }
        if(check)
        cout<<s;
        else
        {
        for(int i=0;i<a*2;i++)
        {
            if(i%2==0)
            s+="B";
            else
            s+="G";
        }
        cout<<s;
        }
    
    }
    else
    {
        while(b>a)
        {
            if(b>=k)
            {
               int h=b-a;
                for(int i=0;i<k && i<h;i++)
                {
                    s+="B";
                    b--;
                }
               
                if(a==b)
                break;
                else
                {
                s+="G";
                a--;}
                
            }
            else
            {
                for(int i=0;i<b;i++)
                s+="B";
                for(int i=0;i<a;i++)
                s+="G";
                check=true;
                break;
            }
            if(a<0)
            {
                s="NO";check=true;break;
            }
        }
        if(check)
        {
        cout<<s;}
        else
        {
        
        for(int i=0;i<b*2;i++)
        {
            if(i%2==0)
            s+="G";
            else
            s+="B";
        }
        cout<<s;
        }
    
    }
    return 0;
}
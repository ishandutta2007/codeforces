#include <iostream>
using namespace std;
string s,q;

void Func1()
{
    q="";
    int x=0;
    for(int i=s.size()-1,ex=1;s[i]>=48 && s[i]<=57;i--,ex*=10)
        x+=ex*(s[i]-'0');
    while(x!=0)
    {
        int a=x%26;
        if(a==0)
        {
            a=26;
            x--;
        }
            
        q+=(a+'0'+16);
        x/=26;
    }
    for(int i=q.size()-1;i>=0;i--)
        cout<<q[i];
    for(int i=1;s[i]>=48 && s[i]<=57;i++)
        cout<<s[i];
    cout<<endl;     
}

void Func2()
{
    int x=0;
    q="";
    for(int i=s.size()-1;i>=0;i--)
        if(s[i]-'0'<0 || s[i]-'0'>9)
            q+=s[i];
    //cout<<q.size();
    cout<<"R";  
    for(int i=0;i<s.size();i++)
        if(s[i]>=48 && s[i]<=57)
            cout<<s[i]; 
    cout<<"C";      
    for(int i=0,ex=1;i<q.size();i++,ex*=26)
        x+=(q[i]-16-'0')*ex;
    cout<<x;
    cout<<endl;             
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p1=0,p2=0,p=0;
        
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]>=48 && s[j]<=57)
                p1=1;
            else if(p1==1 && p2==1)
            {
                p++;
                Func1();
                break;
            }
            else
                p2++;
        }
        if(p==0)
            Func2();    
    }
    
    
    
    return 0;
}
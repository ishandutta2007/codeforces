#include <iostream>

using namespace std;

int tool(char a[])
{
    int p=0;
    for(int i=0;a[i]!=0;i++)
       p++;
    return p;   
}
int main() {
    
    char a[200],b[200],c[200];
    cin>>a>>b;
    int t=tool(a);
    int t2=tool(b);
    for(int i=0;i<t;i++)
    {
        c[t-i-1]=a[i];
    } 
    if(t!=t2)
        cout<<"NO";
    else if (t==t2)
    {
        int p=0;
        for(int i=0;i<t;i++)
        {
            if(b[i]!=c[i])
            {
                p++;
                break;
            }
        }
        if(p==0)
          cout<<"YES";
        if(p!=0)
          cout<<"NO";  
    }   
       
    return 0;
}
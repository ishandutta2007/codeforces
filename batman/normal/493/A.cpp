#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<" ";}


char a[30],b[30];
int t1[110],t2[110];
int main()
{
    
    ll n;
    cin>>a>>b;
    cin>>n;
    ll t,num;
    char ex,card;
    for(int i=0;i<n;i++)
    {
        cin>>t>>ex>>num>>card;
        if(ex=='h')
        {
            if(card=='r' && t1[num]<2)
            {
                t1[num]=2;
                prt(a);
                cout<<num<<" "<<t<<endl;
            }
            else if(card=='y' && t1[num]<2)
            {
                if(t1[num]==1)
                {
                    t1[num]=2;
                    prt(a);
                    cout<<num<<" "<<t<<endl;
                }
                else
                    t1[num]=1;
            }
        }
        if(ex=='a')
        {
            if(card=='r' && t2[num]<2)
            {
                t2[num]=2;
                prt(b);
                cout<<num<<" "<<t<<endl;
            }
            else if(card=='y' && t2[num]<2)
            {
                if(t2[num]==1)
                {
                    t2[num]=2;
                    prt(b);
                    cout<<num<<" "<<t<<endl;
                }
                else
                    t2[num]=1;
            }
        }
    }
    
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<double> a;

int main() 
{
int q;
cin>>q;
int cas;
double temp;
double now = -1;
double sumcurrent = 0;
for (int i = 0; i<q; i++)
{
    cin>>cas;
    if (cas==1) {cin>>temp; a.push_back(temp);}
    else
    {
        if (a[0]==a[a.size()-1]) cout<<0<<endl;
        else
        {
            while ((now<a.size()-2)&&((sumcurrent+a[a.size()-1])*(now+3)>(sumcurrent+a[a.size()-1] + a[now+1])*(now+2))) {now++; sumcurrent+=a[now];}
            cout<<setprecision(10)<<(a[a.size()-1]-(sumcurrent+a[a.size()-1])/(now+2))<<endl;
        }
            
            
            
        
    }
}

}
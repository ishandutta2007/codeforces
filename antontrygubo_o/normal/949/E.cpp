#include<bits/stdc++.h>
using namespace std;

int price(vector<int> a)
{
    int countt = 0;
    for (int i = 0; i<a.size(); i++) if (a[i]!=0) countt++;
    return countt;
}

int low(int a)
{
    if (a%2==0) return a/2;
    return (a-1)/2;
}

int high(int a)
{
    if (a%2==0) return a/2;
    return (a+1)/2;
}

vector<int> f(vector<int> a)
{
    bool chet = true;
    for (int i = 0; i<a.size(); i++) if (a[i]%2!=0) chet = false;
    if (chet)
    {
        for (int i = 0; i<a.size(); i++) a[i]/=2;
        vector<int> temp = f(a);
        temp.push_back(0);
        return temp;
    }
    else
    {
        vector<int> blow;
        if (low(a[0])!=0) blow.push_back(low(a[0]));
        for (int i = 1; i<a.size(); i++) if ((low(a[i])!=low(a[i-1]))&&(low(a[i])!=0)) blow.push_back(low(a[i]));
        vector<int> bhigh;
        if (high(a[0])!=0) bhigh.push_back(high(a[0]));
        for (int i = 1; i<a.size(); i++) if ((high(a[i])!=high(a[i-1]))&&(high(a[i])!=0)) bhigh.push_back(high(a[i]));
        if (blow.size()==0) {vector<int> temp; temp.push_back(1); return temp;}
        if (bhigh.size()==0) {vector<int> temp; temp.push_back(-1); return temp;}
        vector<int> templ = f(blow);
        vector<int> temph = f(bhigh);
        
        if (price(temph)>price(templ))
        {
            templ.push_back(1);
            return templ;
        }
        else
        {
            temph.push_back(-1);
            return temph;            
        }
    }
}

int main()
{
   int n;
   cin>>n;
   int k[n];
   for (int i = 0; i<n; i++) cin>>k[i];
   sort(k, k+n);
   vector<int> a;
   if (k[0]!=0) a.push_back(k[0]);
   for (int i = 1; i<n; i++) {if ((k[i]!=0)&&(k[i]!=k[i-1])) a.push_back(k[i]);}
   if (a.size()==0) {cout<<0; return 0;}
   vector<int> temp = f(a);
   cout<<price(temp)<<endl;
   int deg2 = 1;
   for (int i = 0; i<temp.size(); i++)
   {
       if (temp[temp.size()-1-i]!=0) cout<<deg2*temp[temp.size()-1-i]<<' ';
       deg2*=2;
   }
   
   
    
}
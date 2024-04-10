#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;
map<string,int> abcde;
int main()
{
    int n,i,s;
    string k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
         cin>>k;
         abcde[k]++;
         s=abcde[k];
         if(s==1)cout<<"OK"<<endl;
         else cout<<k<<s-1<<endl;
    }
         
    //system("pause");
    return 0;
}
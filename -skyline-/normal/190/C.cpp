#include<cstdlib>
#include<iostream>       
using namespace std;
int t,c;
string s,z;
void a()
{
    if(cin>>s)
    {
         z+=s;
         if(s=="pair")
         {
             z+="<",a(),z+=",",a(),z+=">";
         }
    }
         
    else t=1;
}

int main()
{
     
    
    cin>>c;
    a();
    if(t||cin>>s)cout<<"Error occurred";
    else cout<<z;
    cout<<endl;
    //system("pause");
    return 0;
}
#include <iostream>
using namespace std;
string a,b;
int x;
int main()
{
    cin>>a>>b;
    for(int i=0;i<a.size();i+=2)
    {
        if((a[i]=='[' && b[i]=='8') || (a[i]=='(' && b[i]=='[') || (a[i]=='8' && b[i]=='('))
            x--;
        else if(a[i]!=b[i])
            x++;
    }
    if(x==0)
        cout<<"TIE";
    else if(x>0)
        cout<<"TEAM 1 WINS"<<endl;
    else
        cout<<"TEAM 2 WINS"<<endl;           

    return 0;
}
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
int i,n;
int h1,a1,c,h2,a2,kol=0;
int th1,ta1,tc,th2,ta2;\
string s;
cin>>h1>>a1>>c;
cin>>h2>>a2;
th1=h1; th2=h2; ta1=a1; ta2=a2; tc=c;
while (h2>0)  {
  if (h1>a2 || h2<=a1) {
    s=s+"1";
    //cout<<"STRIKE";
    kol++;
    h2=h2-a1;
    h1=h1-a2;
   } else{
    s=s+"0";
    //cout<<"HEAL";
    h1=h1-a2+c;
    kol++;
   }
}
h1=th1; h2=th2; a1=ta1; a2=ta2; c=tc;
//cout<<h1<<" "<<h2<<" "<<a1<<" "<<a2<< " "<<c<<endl;
cout<<kol<<endl;
while (h2>0)  {
  if (h1>a2 || h2<=a1) {
    s=s+"1";
    cout<<"STRIKE"<<endl;
    //kol++;
    h2=h2-a1;
    h1=h1-a2;
   }
  else{
    s=s+"0";
    cout<<"HEAL"<<endl;
    h1=h1-a2+c;
    //kol++;
   }
}


    return 0;
}
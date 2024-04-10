#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const string rmd[8]={"1869","1968","1689","6198","1698","1986","1896","1869"};
const int ten[6]={1,3,2,6,4,5};
const int rev[7]={0,1,4,5,2,3,6};
bool temp[4]={true,true,true,true};
int main(){
    string s,t;
    cin>>s;
    int i,d,j;
    int rem=0;
    for(i=s.size()-1;i>=0;i--){
        if(temp[0]&&s[i]=='1'){
            temp[0]=false;
        }
        else if(temp[1]&&s[i]=='6'){
            temp[1]=false;
        }
        else if(temp[2]&&s[i]=='8'){
            temp[2]=false;
        }
        else if(temp[3]&&s[i]=='9'){
            temp[3]=false;
        }
        else{
            t.push_back(s[i]);
            rem=(rem*3+(s[i]-'0'))%7;
        }
    }
    t=rmd[((7-rem)*rev[ten[(s.size()-4)%6]])%7]+t;
    cout<<t<<endl;
    return 0;
}
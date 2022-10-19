#include <iostream>
#include <string>

using namespace std;

string s;
long n;

bool check(void){
    long a=0,k=0;
    n=s.length();
    for (long i=0; i<n; ++i){
        if (s[i]=='.'){
            if (k==0 && a>8)
            return 0;
            if (a==0)
            return 0;
            if (k>0 && a<2)
            return 0;
            if (a>11)
            return 0;
            k++;
            a=0;
        }
        else
        a++;
    }
    if (a==0 || a>3)
    return 0;
    if (k==0)
    return 0;
    return 1;
}

void write(void){
    string t="";
    long k=0,a=0;
    for (long i=0; i<n; ++i){
        if (s[i]=='.'){
            if (k==0){
                cout<<t<<".";
            }
            if (k>0)
            if (a>8)
            cout<<t.substr(0,3)<<"\n"<<t.substr(3,(a-3))<<".";
            else
            cout<<t.substr(0,1)<<"\n"<<t.substr(1,(a-1))<<".";
            k++;
            t.clear();
            a=0;
        }
        else{
            a++;
            t=t+s[i];
        }
    }
    cout<<t;
}



int main()
{
    cin>>s;
    if (!check())
    cout<<"NO";
    else{
        cout<<"YES\n";
        write();
    }
    return 0;
}
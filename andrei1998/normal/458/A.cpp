#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int frecv[100005];

int main()
{
    string a,b;
    cin>>a>>b;

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0;i<a.size();i++)
        frecv[i]+=(a[i]-'0');

    for(int i=0;i<b.size();i++)
        frecv[i]-=(b[i]-'0');

    bool plus=false;
    bool minus=false;

    for(int i=100000;i>=2 && !plus && !minus;i--)
    {
        if(frecv[i]>0){
            if(frecv[i]>=2)
                plus=1;
            else if(frecv[i-1]>=0)
                plus=1;
            else{
                frecv[i-1]++;
                frecv[i-2]++;
                frecv[i]=0;
            }
        }
        else if(frecv[i]<0){
            if(frecv[i]<=-2)
                minus=1;
            else if(frecv[i-1]<=0)
                minus=1;
            else{
                frecv[i-1]--;
                frecv[i-2]--;
                frecv[i]=0;
            }
        }
    }

    if(plus){
        cout<<">\n";
        return 0;
    }
    else if(minus){
        cout<<"<\n";
        return 0;
    }


    if(!frecv[0] && !frecv[1]){
        cout<<"=\n";
        return 0;
    }

    long double aux=frecv[0]+1.61803398874989l*frecv[1];
    if(aux>0l)
        cout<<">\n";
    else
        cout<<"<\n";
    return 0;
}

/*#include <iostream>
#include <iomanip>

using namespace std;

const long double phi=1.61803398874989l;

long double p[50];
long double s[50];

int main()
{
    p[0]=1;
    s[0]=1;
    for(int i=1;i<=50;i++){
        p[i]=(p[i-1]*phi);
        s[i]=p[i]+s[i-1];
    }

    for(int i=0;i<=50;i++)
        cout<<fixed<<setprecision(8)<<i<<' '<<s[i]<<' '<<2*p[i+1]<<endl;

    return 0;
}*/
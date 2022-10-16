#include <iostream>
#include <iomanip>

using namespace std;

int n,centru;
int l[10];
int r[10];

int vars (int i, int tip) {
    if(!tip) {
        if(l[i]<=centru && centru<=r[i])
            return centru-l[i];
        else if(r[i]<centru)
            return r[i]-l[i]+1;
        return 0;
    }
    else if(tip==1)
        return ((bool)(l[i]<=centru && centru<=r[i]));
    else {
        if(l[i]<=centru && centru<=r[i])
            return r[i]-centru;
        else if(centru<l[i])
            return r[i]-l[i]+1;
        return 0;
    }
}

int tip[10];
int _s[3];

double sum;
void backtr (int poz) {
    if(poz==(n+1)) {
        if(!_s[1])
            return;
        if(_s[2]>=2)
            return;
        if(_s[2]==0) {
            if(_s[1]==1)
                return;
        }

        double prod=1;
        for(int i=1;i<=n;i++)
            prod*=vars(i,tip[i]);
        sum+=centru*prod;

        return;
    }

    for(int i=0;i<3;i++) {
        _s[i]++;

        tip[poz]=i;
        backtr(poz+1);

        _s[i]--;
    }
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>l[i]>>r[i];

    for(int i=1;i<=10000;i++) { //A doua valoare - REMINDER 10000
        centru=i;
        backtr(1);
    }

    for(int i=1;i<=n;i++) {
        sum/=(r[i]-l[i]+1);
    }

    cout<<fixed<<setprecision(12)<<sum<<'\n';
    return 0;
}
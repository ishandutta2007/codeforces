#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int n,m,x;


int main(){
    scanf("%d %d %d",&n,&m,&x);
    int y=1;

    while (n>0 && m>0){
        int sum;
        int sum11=(n/2)+(n%2);
        int sum21=n-sum11;
        int sum1=((m/2)+(m % 2))*sum11+(m-(m/2)-(m % 2))*sum21;
        int n1=n-2;
        int m1=m-2;
        if (n1<=0 || m1<=0){
            sum=sum1;
        }
        else {
            int sum12=(n1/2)+(n1%2);
            int sum22=n1-sum12;
            int sum2=((m1/2)+(m1 % 2))*sum12+(m1-(m1/2)-(m1 % 2))*sum22;
            sum=sum1-sum2;
        }

        if (y==x){
            cout<<sum;
            return 0;
        }
        n-=2;
        m-=2;
        ++y;
    }
    cout<<"0";
    return 0;
}
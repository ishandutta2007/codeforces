#include <iostream>
#include <vector>

using namespace std;

long long a,b,c,sum,ls;
long long x,def;
vector<long> answer;

inline long pow(long long x,long long p){
    long long ans=1;
    for(size_t i=1;i<=p;i++) ans *= x;
    return ans;
}

int main()
{
    cin >> a >> b >> c;
    for(sum=1;sum <=81;sum++){
        x = b*pow(sum,a)+c;
        if(x >= 1e9 || x < 0) continue;

         ls = 0; def = x;
         while(x) {
            ls += x % 10;
            x /= 10;
         }
         if(ls != sum) continue;
         answer.push_back(def);

    }

    cout << answer.size() << '\n';
    for(sum = 0;sum < answer.size();sum++) cout << answer[sum] << ' ';


    return 0;
}
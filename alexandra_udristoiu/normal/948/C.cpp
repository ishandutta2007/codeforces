#include<iostream>
#include<set>
using namespace std;
int n, i, x;
long long sum, sol;
int v[100005];
multiset<long long> s;
multiset<long long> :: iterator it;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        cin>> x;
        s.insert(v[i] + sum);
        sum += x;
        sol = 0;
        while(!s.empty()){
            it = s.begin();
            if(*it <= sum){
                sol += *it - (sum - x);
                s.erase(it);
            }
            else{
                break;
            }
        }
        cout<< sol + s.size() * x <<" ";
    }
}
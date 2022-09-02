#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
    cin>>t;
    while (t--){
        long long n,W,result;
		multiset <long long> s;
        cin>>n>>W;
        long long weights[n+3];
        for (long long i=1;i<=n;++i){
            cin>>weights[i];
            s.insert(weights[i]);
        }
        long long tempS=W; 
        result=1;
        while(s.size()){
        	auto calc=s.upper_bound(tempS);
        	bool f= true;
        	if (calc!=s.begin()) 
        		calc--;
        	else 
        		f = false;
        	if (f){
        	            		tempS-=*calc;
        		s.erase(calc);

        	}
        	else{
        		result++;
        		tempS=W;
        	}
        }
        cout<<result<<endl;
    }
}
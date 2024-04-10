// Code has been based on a page on GeeksForGeeks which was published before the contest

#include <bits/stdc++.h> 
using namespace std; 

long long fpp(long long fact, long long p) 
{ 
    long long res = 0; 
    while (fact > 0) {         
        res += fact / p; 
        fact /= p; 
    } 
  
    return res; 
} 
 
long long fpc(long long fact, long long n) 
{ 
    long long res = 1e20; 
  
    for (long long i = 2; i <= sqrt(n); i++) {         
        long long count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
  
        if (count > 0) { 
            long long cp = fpp(fact, i) / count; 
            res = min(res, cp);
            //std::cout << count << std::endl;
         } 
    } 
  
    if (n >= 2) { 
        long long cp  = fpp(fact, n); 
        res = min(res, cp); 
    } 
  
    return res; 
} 
  
int main() 
{ 
    long long fact, n;
    std::cin >> fact >> n;
    cout << fpc(fact, n); 
    return 0; 
}
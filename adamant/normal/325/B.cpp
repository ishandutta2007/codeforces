#include <iostream>
#define w while
int main() 
{
  long long n, f=0,p,x,N;
  std::cin >> n;

  for (p=0; p<63; p++) {
    x = 1, N = ((1LL << p)-1)*2-1;
    w (x+N < n*2/x) x += 10240;
    w (x > 1e3 && x+N > n*2/x) x -= 1024;
    w (x*(x+N) < n*2) x += 2;
    if (x*(x+N) == n*2)
    std::cout << (f = x * (1LL << p))<<' ';
  }

  if (!f)std::cout<<-1;
}
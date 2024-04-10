
def exgcd(a, b):
    if b == 0: return (a, 1, 0)
    g, y, x = exgcd(b, a%b)
    return (g, x, y-x*(a//b))

def crt(a1, m1, a2, m2):
    g = exgcd(m1, m2)[0]
    
    e1, e2 = a1%g, a2%g
    if e1 != e2: return None

    a1 //= g 
    m1 //= g 
    a2 //= g
    m2 //= g

    (_, m1i, m2i) = exgcd(m1, m2)

    ans = a1*m2*m2i + a2*m1*m1i
    
    ans = ans%(m1*m2)
    if ans < 0: ans += m1*m2

    return ans*g + e1


def solve(N, M, x, y, vx, vy):
  if vx == 0:
    if x == 0 or x == N: return (x, 0)
    else: return None
  if vy == 0:
    if y == 0 or y == M: return (0, y)
    else: return None
  
  ans = crt(x, N, y, M)
  #print(ans)
  if ans is None: return ans

  xhit, yhit = (ans+N-1) // N, (ans+M-1) // M
  if x == 0: xhit -= 1
  if y == 0: yhit -= 1
  #print(xhit, yhit)

  return (N if xhit%2 == 0 else 0, M if yhit%2 == 0 else 0)

def main():
  N, M, x, y, vx, vy = map(int, input().split())

  swapx, swapy = False, False

  if vx > 0:
    swapx = True
    x = N-x
  
  if vy > 0:
    swapy = True
    y = M-y
    
  ans = solve(N, M, x, y, vx, vy)
  if ans is None: print(-1)
  else:
    ax, ay = ans
    if swapx: ax = N-ax
    if swapy: ay = M-ay 
    print(ax, ay)


if __name__ == '__main__':
  main()
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S1 = input().strip()
    S2 = input().strip()
    S3 = input().strip()
    
    for s1 in (S1, S2, S3):
        for s2 in (S1, S2, S3):
            if s1 == s2:
                continue
            z1 = s1.count("0")
            o1 = s1.count("1")
            z2 = s2.count("0")
            o2 = s2.count("1")
            mz = max(z1, z2)
            mo = max(o1, o2)
            if mz > n and mo > n:
                continue
            
            if mz <= n:
                cnt1 = []
                cnt2 = []
                bef = "0"
                cnt = 0
                for s in s1:
                    if s == "1":
                        cnt1.append(cnt)
                        cnt = 0
                    else:
                        cnt += 1
                    bef = s
                if cnt:
                    cnt1.append(cnt)
                    
                bef = "0"
                cnt = 0
                for s in s2:
                    if s == "1":
                        cnt2.append(cnt)
                        cnt = 0
                    
                    else:
                        cnt += 1
                    bef = s
                if cnt:
                    cnt2.append(cnt)
                    
                if len(cnt1) > len(cnt2):
                    cnt2 += [0] * (len(cnt1) - len(cnt2))
                elif len(cnt1) < len(cnt2):
                    cnt1 += [0] * (len(cnt2) - len(cnt1))
                
                ans = []
                for c1, c2 in zip(cnt1, cnt2):
                    ans += ["0"] * max(c1, c2)
                    ans += ["1"]
                ans.pop()
                if len(ans) < 3 * n:
                    ans += ["1"] * (3 * n - len(ans))
                
                
                print("".join(ans))
                return
            
            elif mo <= n:
                cnt1 = []
                cnt2 = []
                bef = "1"
                cnt = 0
                for s in s1:
                    if s == "0":
                        cnt1.append(cnt)
                        cnt = 0
                    else:
                        cnt += 1
                    bef = s
                if cnt:
                    cnt1.append(cnt)
                    
                bef = "1"
                cnt = 0
                for s in s2:
                    if s == "0":
                        cnt2.append(cnt)
                        cnt = 0
                    
                    else:
                        cnt += 1
                    bef = s
                if cnt:
                    cnt2.append(cnt)
                    
                if len(cnt1) > len(cnt2):
                    cnt2 += [0] * (len(cnt1) - len(cnt2))
                elif len(cnt1) < len(cnt2):
                    cnt1 += [0] * (len(cnt2) - len(cnt1))
                
                ans = []
                for c1, c2 in zip(cnt1, cnt2):
                    ans += ["1"] * max(c1, c2)
                    ans += ["0"]
                ans.pop()
                
                if len(ans) < 3 * n:
                    ans += ["0"] * (3 * n - len(ans))

                
                print("".join(ans))
                return

    
for _ in range(int(input())):
    main()
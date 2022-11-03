n=gets.to_i
s=gets.to_s
p=s.chomp.split("")
x=1;
10000.times do
  x*=10;
end
dp = Array.new(100,x)
dp[0]=0;
y=p.size.to_i
for i in 0..y-1 do
  tmp=0
  j=i
  while j<y&&tmp*10+p[j].to_i<n do
    tmp=tmp*10+p[j].to_i
    dp[j+1]=[dp[j+1],dp[i]*n+tmp].min
    if p[i].to_i == 0
      break
    end
    j+=1
  end
end
puts dp[y]
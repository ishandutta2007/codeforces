uses math;
var s:ansistring;
    k,ans:array [0..1000001] of longint;
    i,j,n:longint;
begin        
readln (s);
n:=length(s);
k[n+1]:=1;
for i:=n downto 1 do
  begin
    if s[i]='1' 
     then
      begin
        ans[i]:=ans[i+1]+1;
        k[i]:=min(k[i+1],ans[i+1]+1);
        ans[i]:=min (ans[i],k[i]+1);
      end 
     else
      begin
        ans[i]:=ans[i+1];
        k[i]:=k[i+1]+1;
        ans[i]:=min (ans[i],k[i]);
      end;
  end;
write (ans[1]);
end.
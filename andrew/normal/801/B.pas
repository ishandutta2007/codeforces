var
 s,s1,s2:ansistring;
 c,c1,c2:char;
 i,j,n,m,k,sc:longint;
function min(a,b:char):char;
begin
 if a<b then min:=a else min:=b;
end;
begin
 readln(s1);
 readln(s2);
 for i:=1 to length(s1) do
 begin
  if s1[i]=s2[i] then begin s:=s+s1[i]; continue; end;
  if s1[i]<s2[i] then begin writeln(-1); halt; end;
  s:=s+min(s1[i],s2[i]);
 end;
 writeln(s);
end.
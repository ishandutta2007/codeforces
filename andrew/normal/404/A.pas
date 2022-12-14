var
 a:array[1..1000,1..1000]of char;
 v,dp:char;
 sc1,sc2,sc3,i,j,k,l,n,m,p,o,c:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  for j:=1 to n do read(a[i,j]);
  readln;
 end;
 v:=a[1,1];
 dp:=a[1,2];
 if v=dp then begin writeln('NO'); halt; end;
 a[1,1]:=dp;
 for i:=2 to n do
 begin
  if a[i,i]<>v then begin writeln('NO'); halt;  end;
  a[i,i]:=dp;
 end;
 if a[1,n]<>v then begin writeln('NO'); halt; end;
 a[1,n]:=dp;
 a[(n div 2)+(n mod 2),(n div 2)+(n mod 2)]:=v;
 for i:=1 to n-1 do
 begin
  if a[i+1,n-i]<>v then begin writeln('NO'); halt;  end;
  a[i+1,n-i]:=dp;
 end;
 for i:=1 to n do
 for j:=1 to n do if a[i,j]<>dp then begin writelN('NO'); halt; end;
 writeln('YES');
end.
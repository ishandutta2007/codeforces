var
 s,s1:ansistring;
 m,n,i,j,sc:longint;
procedure swap(var a,b:char);
var c:char;
begin
 c:=a;
 a:=b;
 b:=c;
end;
begin
 readln(s);
 s1:=s;
 n:=length(s);
 for i:=1 to n div 2 do swap(s1[i],s1[n-i+1]);
 if s1=s then
 begin
  if n mod 2=0 then begin writeln('NO'); halt; end;
  writeln('YES');
  halt;
 end;
 for i:=1 to n div 2 do if s[i]<>s1[i] then inc(sc);
 if sc=1 then writeln('YES') else writeln('NO');
end.
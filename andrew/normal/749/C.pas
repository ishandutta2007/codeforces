var
 a:array[1..1000000]of longint;
 s:ansistring;
 r1,r2,d1,d2:longint;
 n,i,j,i1,j1,ch1,ch2,k,l,o,p,d:longint;
begin
 readln(n);
 readln(s);
 for i:=1 to n do
  if s[i]='D'then inc(r1)else inc(r2);
  while (r1<>0)and(r2<>0)do
 for i:=1 to n do if a[i]=0 then
 begin
  if (s[i]='D')and(d1>0)then begin a[i]:=1; dec(d1);dec(r1);continue; end else
  if (s[i]='R')and(d2>0)then begin a[i]:=1; dec(d2);dec(r2);continue; end;
  if s[i]='D'then
   inc(d2) else
   inc(d1);
 end;
 if r1=0 then writeln('R')else writeln('D');
end.
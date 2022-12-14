var
 a:array[1..1000,1..1000]of char;
 vi:char;
 i,j,k,l,n,m,v,d,f,sc,f1,c1,c2:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  for j:=1 to n do read(a[i,j]);
  readln;
 end;
 sc:=0;
 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   if (a[i,j]='#')and(j<>1)and(i<>n) then
   begin
    sc:=0;
    for k:=i+1 to i+2 do if a[k,j]='#' then inc(sc);
    if sc<>2 then continue;
    f:=i+1;
    f1:=j-1;
    for k:=f1 to f1+2 do if a[f,k]='#' then inc(sc);
    if sc=5 then
    begin
      for k:=i to i+2 do a[k,j]:='.';
      for k:=f1 to f1+2 do  a[i+1,k]:='.';
    end;
   end;
  end;
 end;
 sc:=0;
 for i:=1 to n do for j:=1 to n do if a[i,j]='#' then inc(sc);
 if sc=0 then writeln('YES') else
 writeln('NO');
end.
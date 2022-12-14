var
 a:array[1..100,1..100]of longint;
 sc,k,m,n,i,j,ch1:longint;
begin
 readln(n,m);
 for i:=1 to n do
  for j:=i to n do
  begin
   if i=j then
   begin
    dec(m);
    if 0>m then begin inc(m); continue; end;
    a[i,j]:=1;
    continue;
   end;
   dec(m,2);
   if 0>m then begin inc(m,2); continue; end;
   a[i,j]:=1;
   a[j,i]:=1;
  end;
 if m>0 then
 begin
  writeln(-1);
  halt;
 end;
 for i:=1 to n do
 begin
  for j:=1 to n-1 do write(a[i,j],' ');
  writeln(a[i,n]);
 end;
end.
var a:array[0..51,0..51] of longint;
    n,m,k,l,i,f:longint;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  readln(k,l);
  inc(a[k,l]);
 end;
 for i:=50 downto 1 do
  for f:=1 to 50 do
   begin
    m:=m-a[i,f];
    if m<=0 then begin writeln(a[i,f]);halt(0)end;
   end;
end.
var n,m,k,i,o:longint;
begin
 readln(n,m,k);if k=1 then o:=1 else o:=0;
 if (n=2)and(m=2)and(k=1) then begin writeln(4);write(1,' ',2,' ',3,' ',4);end else
 if n=m then
 begin
  writeln(2*k+1);
  for i:=1 to k do
   write('1 ');
  write(n,' ');
  for i:=1 to k-1 do
   write(n+1,' ');
  writeln(n+2);
 end else
 begin
  if not((n-m>1)and(k=1)) then writeln(2*k+o) else writeln(2*k);
  for i:=1 to k do
   write('1 ');
  write(n,' ');
  if not((n-m>1)and(k=1)) then
  for i:=1 to k+o-1 do
   if i<k-1 then write(n+1,' ') else writeln(n+1);
 end;
end.
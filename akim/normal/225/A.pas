var n,m,k,l,i:longint;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  readln(k,l);
  if (k=m)or(k=7-m)or(l=m)or(l=7-m) then begin writeln('NO');halt(0);end;
 end;
 writeln('YES');
end.
var m,mi,k,x,i,n:longint;
begin
 readln(n);m:=$7fffffff;
 for i:=1 to n do
 begin
  read(x);
  if x=m then inc(k);
  if x<m then begin m:=x;mi:=i;k:=1;end;
 end;
 if k=1 then writeln(mi) else writeln('Still Rozdil');
end.
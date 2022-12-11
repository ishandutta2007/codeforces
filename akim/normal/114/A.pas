var n,c,o,m:int64;
begin
 readln(n,m);
 c:=n;o:=0;
 while c<m do
 begin
  c:=c*n;
  inc(o);
 end;
 if m=c then begin writeln('YES');writeln(o);end else writeln('NO');
end.
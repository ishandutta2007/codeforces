uses math;
var
  n,m:longint;
begin
  read(n,m);
  if n+m=0 then begin writeln('0 0'); halt; end;
  if n=0 then begin writeln('Impossible'); halt; end;
  if m>n then write(m,' ') else write(n,' ');
  if m=0 then writeln(n) else writeln(n+m-1);
end.
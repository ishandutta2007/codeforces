uses math;
var
  k,l,ans:longint;
  i:longint;
begin
  read(k,l);
  ans:=0;

  repeat
    inc(ans);
    if l mod k<>0 then begin writeln('NO'); halt; end;
    l:=l div k;
  until l=1;
  writeln('YES');
  writeln(ans-1);
end.
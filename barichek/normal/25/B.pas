uses math;
var
  s,ans:ansistring;
  n:longint;
  i:longint;
begin
  readln(n);
  read(s);

  if n mod 2=0 then begin i:=3; ans:=ans+copy(s,1,2) end
  else begin i:=4; ans:=ans+copy(s,1,3); end;

  if (n=2) or (n=3) then begin writeln(ans); halt; end;
  repeat
    ans:=ans+'-';
    ans:=ans+copy(s,i,2);
    inc(i,2);
  until i=n+1;

  writeln(ans);
end.
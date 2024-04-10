uses math;
var
  r1,c1,r2,c2:longint;
  ans1,ans2,ans3:longint;
begin
  read(r1,c1,r2,c2);
  if (r1=r2) and (c1=c2) then begin writeln(0,' ',0,' ',0); halt; end;

  if (r1=r2)  or (c1=c2) then ans1:=1
  else ans1:=2;

       if (r1+c1)mod 2<>(r2+c2)mod 2 then ans2:=0
  else if abs(r1-r2)-abs(c1-c2)=0   then ans2:=1
  else                                    ans2:=2;

  ans3:=max(abs(r2-r1),abs(c2-c1));
  writeln(ans1,' ',ans2,' ',ans3);
end.
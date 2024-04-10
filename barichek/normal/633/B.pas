uses math;
var
  n,anskil:longint;
  ans,dop:ansistring;
  i,idop,pot2,pot5:longint;
begin
  read(n);

  i:=1;
  while i<>-1 do
    begin
      idop:=i;
      while idop mod 2=0 do
        begin
          inc(pot2);
          idop:=idop div 2;
        end;
      while idop mod 5=0 do
        begin
          inc(pot5);
          idop:=idop div 5;
        end;
      if min(pot2,pot5)=n then
        begin
          inc(anskil);
          str(i,dop);
          if ans<>'' then ans:=ans+' '+dop
          else ans:=ans+dop;
        end;
      if min(pot2,pot5)>n then break;
      inc(i);
    end;

  writeln(anskil);
  writeln(ans);
end.
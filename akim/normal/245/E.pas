var s:ansistring;
    i,iz,iv:longint;
begin
 readln(s);iv:=0;iz:=0;
 for i:=1 to length(s) do
 begin
  case s[i] of
  '+':begin if iz=0 then inc(iz);iv:=iv+1;iz:=iz-1;end;
  '-':begin if iv=0 then inc(iv);iz:=iz+1;iv:=iv-1;end;
  end;
 end;
 writeln(iz+iv);
end.
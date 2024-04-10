uses math;
var
  l,r:int64;
begin
  read(l,r);

  if r-l<2 then begin writeln(-1); halt; end;
  if l mod 2=0 then begin write(l,' ',l+1,' ',l+2); halt; end;
  if (l mod 2=1) and (r-l>2) then begin write(l+1,' ',l+2,' ',l+3); halt; end;
  writeln(-1);
end.
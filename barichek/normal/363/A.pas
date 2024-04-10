uses math;
var
  n,nv:longint;
begin
  read(n);
  repeat
    nv:=n mod 10;
    if nv>=5 then write('-O|')
    else write('O-|');
    nv:=nv mod 5;
    case nv of
      0: write('-OOOO');
      1: write('O-OOO');
      2: write('OO-OO');
      3: write('OOO-O');
      4: write('OOOO-');
    end;
    n:=n div 10;
    writeln;
  until n=0;
end.
uses math;
var
  n:longint;
begin
  read(n);
  if n=0 then begin write('zero'); halt; end;
  if n div 10=1 then
    begin
      case n mod 10 of
        0:write('ten');
        1:write('eleven');
        2:write('twelve');
        3:write('thirteen');
        4:write('fourteen');
        5:write('fifteen');
        6:write('sixteen');
        7:write('seventeen');
        8:write('eighteen');
        9:write('nineteen');
      end;
      halt;
    end;

  case n div 10 of
    2:write('twenty');
    3:write('thirty');
    4:write('forty');
    5:write('fifty');
    6:write('sixty');
    7:write('seventy');
    8:write('eighty');
    9:write('ninety');
  end;

  if (n div 10)*(n mod 10)<>0 then write('-');
  case n mod 10 of
    1:write('one');
    2:write('two');
    3:write('three');
    4:write('four');
    5:write('five');
    6:write('six');
    7:write('seven');
    8:write('eight');
    9:write('nine');
  end;
end.
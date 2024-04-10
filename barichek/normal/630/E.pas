uses math;
var
  x1,y1,x2,y2:int64;
begin
  read(x1,y1,x2,y2);

  writeln((x2-x1)div 2*(2*(y2-y1)div 2+1)+(y2-y1)div 2+1)
end.
import Data.List
main=do--kitten
 (a:as)<-fmap(lines)getContents
 print.length.filter(\s->length(filter(=='Y')s)>=(last.map read$words a))$transpose as